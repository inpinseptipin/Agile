#include "LoginComponent.h"

//==============================================================================
LoginComponent::LoginComponent()
{
    setSize (800, 600);
    
    addAndMakeVisible(_footer);
    addAndMakeVisible(_emailAddress);
    addAndMakeVisible(_loginButton);
    addAndMakeVisible(_signupButton);

    AuxPort::setLProperties(_footer, "All Rights Reserved\nSatyarth Arora ASU2017010100174 \nHimanshu Sindwani ASU2017010100067",juce::Colour(133,142,146),juce::Colour(2,29,39),juce::Font(18,1),juce::Justification(juce::Justification::horizontallyJustified));
    
    AuxPort::setLProperties(_emailAddress, "Enter Email ID", juce::Colour(255, 255, 255), juce::Colour(0, 0, 0), juce::Font(24, 1),juce::Justification(juce::Justification::horizontallyCentred));
    _emailAddress.setEditable(true);
    _emailAddress.setColour(juce::Label::ColourIds::outlineColourId, juce::Colour(0, 0, 0));
    _emailAddress.setColour(juce::Label::ColourIds::textWhenEditingColourId, juce::Colour(0, 0, 0));
    
   

    _emailAddress.onTextChange = [this]
    {

        if (_emailAddress.getText().length() != 10)
            _emailAddress.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colour(255, 0, 0));
        else
        {
            _emailAddress.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colour(0, 255, 0));
        }
            
    };
    
    AuxPort::setTBProperties(_loginButton, "Login",juce::Colour(133, 142, 146),juce::Colour(0,0,0));
    AuxPort::setTBProperties(_signupButton, "Signup", juce::Colour(0,0,0), juce::Colour(255,255,255));
}

LoginComponent::~LoginComponent()
{
}

//==============================================================================
void LoginComponent::paint (juce::Graphics& g)
{
    
}

void LoginComponent::resized()
{
    _emailAddress.setBounds(getRight() / 4, 4 * getBottom() / 10, getRight() / 2, getBottom() / 20);
    _loginButton.setBounds(getRight() / 4, 5*getBottom() / 10, getRight() / 4, getBottom()/20);
    _signupButton.setBounds(getRight()/2, 5 * getBottom() / 10, getRight() / 4, getBottom() / 20);
    _footer.setBounds(0, 9 * getBottom() / 10, getRight(), getBottom() / 10);
}

juce::StringPairArray LoginComponent::getAllValues()
{
    juce::StringPairArray _values;
    _values.set("email", _emailAddress.getText());
    return _values;
}


