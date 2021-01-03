/*
  ==============================================================================

    Automation.cpp
    Created: 26 Dec 2020 6:26:13pm
    Author:  arsen

  ==============================================================================
*/

#include "Automation.h"

namespace AuxPort
{
    void setTBProperties(juce::TextButton& textButton, const juce::String& buttonName, const juce::Colour& buttonColour, const juce::Colour& textColour)
    {
        textButton.setButtonText(buttonName);
        textButton.setColour(juce::TextButton::ColourIds::buttonColourId, buttonColour);
        textButton.setColour(juce::TextButton::ColourIds::textColourOffId, textColour);
    }

    void setLProperties(juce::Label& label, const juce::String& labelName, const juce::Colour& backgroundColour, const juce::Colour& textColour, const juce::Font& font , const juce::Justification& justification)
    {
        label.setText(labelName,juce::dontSendNotification);
        label.setColour(juce::Label::ColourIds::backgroundColourId, backgroundColour);
        label.setColour(juce::Label::ColourIds::textColourId, textColour);
        label.setFont(font);
        label.setJustificationType(justification);
    }


    int Alerts::Question(const juce::String& title, const juce::String& message, const Buttons& warningType)
    {
        juce::AlertWindow alert(title, message, juce::AlertWindow::AlertIconType::QuestionIcon);
        alert.setColour(juce::AlertWindow::ColourIds::backgroundColourId, juce::Colours::black);
        alert.setColour(juce::AlertWindow::ColourIds::textColourId, juce::Colour(255,255,0));
        alert.setColour(juce::AlertWindow::ColourIds::outlineColourId, juce::Colours::black);
        
        switch (warningType)
        {
        case Buttons::Ok:
            alert.addButton("Ok", 1);
            return alert.runModalLoop();
            break;
        case Buttons::YesAndNo:
            alert.addButton("Yes", 1);
            alert.addButton("No", 2);
            return alert.runModalLoop();
            break;
        }
    }

    int Alerts::Warning(const juce::String& title, const juce::String& message)
    {
        juce::AlertWindow alert(title, message, juce::AlertWindow::AlertIconType::WarningIcon);
        alert.setColour(juce::AlertWindow::ColourIds::backgroundColourId, juce::Colours::black);
        alert.setColour(juce::AlertWindow::ColourIds::textColourId, juce::Colour(255, 0, 0));
        alert.setColour(juce::AlertWindow::ColourIds::outlineColourId, juce::Colours::black);

        alert.addButton("Ok", 1);
        return alert.runModalLoop();
    }

    int Alerts::Info(const juce::String& title, const juce::String& message)
    {
        juce::AlertWindow alert(title, message, juce::AlertWindow::AlertIconType::InfoIcon);
        alert.setColour(juce::AlertWindow::ColourIds::backgroundColourId, juce::Colours::black);
        alert.setColour(juce::AlertWindow::ColourIds::textColourId, juce::Colour(23, 255, 23));
        alert.setColour(juce::AlertWindow::ColourIds::outlineColourId, juce::Colours::black);
        
        alert.addButton("Ok", 1);
        return alert.runModalLoop();
    }

    juce::String Alerts::OTP()
    {
        juce::AlertWindow alert("OTP Verification", "An OTP has been sent to your Email ID, Please type in the OTP to Login", juce::AlertWindow::AlertIconType::NoIcon);
        alert.setColour(juce::AlertWindow::ColourIds::backgroundColourId, juce::Colours::black);
        alert.setColour(juce::AlertWindow::ColourIds::textColourId, juce::Colour(0,255,0));
        alert.setColour(juce::AlertWindow::ColourIds::outlineColourId, juce::Colours::black);

        alert.addTextEditor("otp-editor", "Enter OTP here", "OTP Text Bar", false);
        alert.addButton("Verify", 1);
        alert.runModalLoop();
        return alert.getTextEditorContents("otp-editor");
    }

}