/*
  ==============================================================================

    SignUpComponent.h
    Created: 26 Dec 2020 5:25:47pm
    Author:  arsen

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Automation/Automation.h"

//==============================================================================
/*
*/
class SignUpComponent  : public juce::Component
{
public:
    SignUpComponent();
    ~SignUpComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::StringPairArray getAllValues();
    void clear();

    juce::TextButton _register;
    juce::TextButton _back;

private:
    juce::Label _phoneNumber;
    juce::Label _name;
    juce::Label _email;
    juce::ComboBox _framework;
    juce::Label _footer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SignUpComponent)
};
