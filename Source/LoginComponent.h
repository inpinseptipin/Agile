#pragma once

#include <JuceHeader.h>
#include "Automation/Automation.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class LoginComponent  : public juce::Component
{
public:
    //==============================================================================
    LoginComponent();
    ~LoginComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    juce::StringPairArray getAllValues();
    juce::TextButton _loginButton;
    juce::TextButton _signupButton;
    
private:
    //==============================================================================
    juce::Label _footer;
    juce::Label _emailAddress;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LoginComponent)
};
