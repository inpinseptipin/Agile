/*
  ==============================================================================

    This file contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LoginComponent.h"
#include "SignUpComponent.h"
#include "UserInterface/DashboardComponent.h"
#include "UserInterface/SurveyComponent.h"
#include "Network/Rest.h"


//==============================================================================
class AgileUIApplication  : public juce::JUCEApplication
{
public:
    //==============================================================================
    AgileUIApplication() {}

    const juce::String getApplicationName() override       { return "How Agile Are You?"; }
    const juce::String getApplicationVersion() override    { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override             { return true; }

    //==============================================================================
    void initialise (const juce::String& commandLine) override
    {
        // This method is where you should put your application's initialisation code..

        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override
    {
        // Add your application's shutdown code here..
        
            mainWindow = nullptr; // (deletes our window)

    }

    //==============================================================================
    void systemRequestedQuit() override
    {
        // This is called when the app is being asked to quit: you can ignore this
        // request and let the app carry on running, or call quit() to allow the app to close.
        quit();
    }

    void anotherInstanceStarted (const juce::String& commandLine) override
    {
        // When another instance of the app is launched while this one is running,
        // this method is invoked, and the commandLine parameter tells you what
        // the other instance's command-line arguments were.
    }

    //==============================================================================
    /*
        This class implements the desktop window that contains an instance of
        our MainComponent class.
    */
    class MainWindow    : public juce::DocumentWindow
    {
    public:

//==============================================================================
        enum Component
        {
            Login = 0,
            Signup = 1,
            Dashboard = 2,
            Survey = 3
        };
//==============================================================================

        MainWindow (juce::String name)
            : DocumentWindow (name,juce::Colours::white,DocumentWindow::TitleBarButtons::allButtons,true)
        {
            _loginComponent.reset(new LoginComponent());
            _signupComponent.reset(new SignUpComponent());
            _dashboardComponent.reset(new DashboardComponent());
            _surveyComponent.reset(new SurveyComponent());
            
            currentView(Component::Login);

            _loginComponent->_loginButton.onClick = [this]
            {
                _loginComponent->_loginButton.setEnabled(false);
                juce::StringPairArray loginValues = _loginComponent->getAllValues();
                juce::StringPairArray response=AuxPort::JSON::parse(AuxPort::Rest::sendRequest(AuxPort::Rest::Request::POST, _baseUrl + "api/login/", loginValues));
                
                if (response.getValue("status", "Null") == "SUCCESS")
                {
                    juce::String otp = AuxPort::Alerts::OTP();
                    if (otp == response.getValue("otp", "null"))
                    {
                        AuxPort::Alerts::Info("OTP Verified", "You are Now Logged in");
                        currentView(Component::Dashboard);
                    }
                    else
                    {
                        AuxPort::Alerts::Warning("OTP entered was incorrect", "Please Try Again");
                    }
                }
                else
                {
                    AuxPort::Alerts::Warning("Invalid Email Address", "This Email is not registered with us");
                }
                
                _loginComponent->_loginButton.setEnabled(true);
            };

            _loginComponent->_signupButton.onClick = [this]
            {
                currentView(Component::Signup);
            };

            _signupComponent->_back.onClick = [this]
            {
                if (AuxPort::Alerts::Question("Are you sure, you want to go back", "All the data inserted here will be lost", AuxPort::Buttons::YesAndNo) == 1)
                {
                    currentView(Component::Login);
                    _signupComponent->clear();
                }
            };

            _signupComponent->_register.onClick = [this]
            {
                juce::StringPairArray signupValues = _signupComponent->getAllValues();
                //AuxPort::JSON::parse(AuxPort::Rest::sendRequest(AuxPort::Rest::Request::POST, _baseUrl + "api/signup/", signupValues)));
                juce::StringPairArray response = AuxPort::JSON::parse(AuxPort::Rest::sendRequest(AuxPort::Rest::Request::POST, _baseUrl+"signup/", signupValues));
                
                if (response.getValue("status", "Null") == "SUCCESS")
                {
                    juce::String otp=AuxPort::Alerts::OTP();
                    if (otp == response.getValue("otp", "null"))
                    {
                        AuxPort::Alerts::Info("OTP Verified", "You are Now Logged in");
                        currentView(Component::Dashboard);
                    }
                    else
                    {
                        AuxPort::Alerts::Warning("OTP entered was incorrect", "Please Try Again");
                    }
                }
                else
                {
                    AuxPort::Alerts::Warning("Something went wrong", "Please go back to the Login Screen and Try Again");
                }
                 
            };

            _dashboardComponent->_survey.onClick = [this]
            {
                std::vector<AuxPort::TextQuestionModel> textQuestions;
                std::vector<AuxPort::MCQQuestionModel> mcqQuestions;
                textQuestions.push_back({ "TQ_01","Text Question 1" });
                textQuestions.push_back({ "TQ_02","Text Question 2" });
                textQuestions.push_back({ "TQ_03","Text Question 3" });
                textQuestions.push_back({ "TQ_04","Text Question 4" });
                textQuestions.push_back({ "TQ_05","Text Question 5" });
                textQuestions.push_back({ "TQ_06","Text Question 6" });
                textQuestions.push_back({ "TQ_07","Text Question 7" });
                textQuestions.push_back({ "TQ_08","Text Question 8" });
                textQuestions.push_back({ "TQ_09","Text Question 9" });
                textQuestions.push_back({ "TQ_10","Text Question 10" });
                _surveyComponent->reset(SurveyComponent::Question::TEXT, textQuestions,mcqQuestions);
                currentView(Component::Survey);
            };

           
            setResizeLimits(800, 800, 1280, 1024);
            setResizable(true, true);
            setVisible (true);
        }


//==============================================================================        
        void closeButtonPressed() override;
        void currentView(const Component& component);

    private:
        std::unique_ptr<LoginComponent> _loginComponent;
        std::unique_ptr<SignUpComponent> _signupComponent;
        std::unique_ptr<DashboardComponent> _dashboardComponent;
        std::unique_ptr<SurveyComponent> _surveyComponent;
        juce::String _baseUrl = { "http://72f8a5c5a8f9.ngrok.io/" };
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (AgileUIApplication)



//==============================================================================
void AgileUIApplication::MainWindow::closeButtonPressed()
{
    if(AuxPort::Alerts::Question("Warning", "Do you want to exit How Agile Are You", AuxPort::Buttons::YesAndNo) ==1)
        JUCEApplication::getInstance()->systemRequestedQuit();
}

//==============================================================================
void AgileUIApplication::MainWindow::currentView(const Component& component)
{
    switch (component)
    {
    case Component::Login:
        setContentNonOwned(_loginComponent.get(), false);
        break;

    case Component::Signup:
        setContentNonOwned(_signupComponent.get(), false);
        break;

    case Component::Dashboard:
        setContentNonOwned(_dashboardComponent.get(), false);
        break;

    case Component::Survey:
        setContentNonOwned(_surveyComponent.get(), false);
        break;
    }
}



