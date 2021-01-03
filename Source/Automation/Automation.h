/*
  ==============================================================================

    Automation.h
    Created: 26 Dec 2020 6:11:01pm
    Author:  arsen

  ==============================================================================
*/

#pragma once

#include<JuceHeader.h>

namespace AuxPort
{

    enum Buttons
    {
        Ok = 1,
        YesAndNo = 2
    };


    void setTBProperties(juce::TextButton& textButton, const juce::String& buttonName, const juce::Colour& buttonColour = juce::Colour(255, 255, 255), const juce::Colour& textColour = juce::Colour(0, 0, 0));
    
    void setLProperties(juce::Label& label, const juce::String& labelName, const juce::Colour& backgroundColour = juce::Colour(255, 255, 255), const juce::Colour& textColour = juce::Colour(0, 0, 0), const juce::Font& font = juce::Font(18, 1), const juce::Justification& justification = juce::Justification(juce::Justification::horizontallyCentred));

    
    class Alerts
    {
    public:
        static int Question(const juce::String& title, const juce::String& message, const Buttons& warningType);
        static int Warning(const juce::String& title, const juce::String& message);
        static int Info(const juce::String& title, const juce::String& message);
        static juce::String OTP();
    };

    
    
}