/*
  ==============================================================================

    DashboardComponent.h
    Created: 27 Dec 2020 8:12:12pm
    Author:  arsen

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../Automation/Automation.h"

//==============================================================================
/*
*/
class DashboardComponent  : public juce::Component
{
public:
    DashboardComponent();
    ~DashboardComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::TextButton _survey;
    juce::TextButton _result;
private:
    juce::Label _footer;
    juce::Label _surveyLabel;
    juce::Label _resultLabel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DashboardComponent)
};
