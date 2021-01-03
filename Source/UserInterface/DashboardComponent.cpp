/*
  ==============================================================================

    DashboardComponent.cpp
    Created: 27 Dec 2020 8:12:12pm
    Author:  arsen

  ==============================================================================
*/

#include <JuceHeader.h>
#include "DashboardComponent.h"

//==============================================================================
DashboardComponent::DashboardComponent()
{
    addAndMakeVisible(_survey);
    addAndMakeVisible(_result);
    addAndMakeVisible(_footer);
    addAndMakeVisible(_surveyLabel);
    addAndMakeVisible(_resultLabel);

    AuxPort::setTBProperties(_survey, "",juce::Colour(0,0,0),juce::Colour(255,255,255));
    AuxPort::setTBProperties(_result, "", juce::Colour(0, 0, 0), juce::Colour(255, 255, 255));

    AuxPort::setLProperties(_surveyLabel, "Surveys", juce::Colours::transparentBlack, juce::Colour(255, 255, 255),juce::Font(24,1));
    AuxPort::setLProperties(_resultLabel, "Results", juce::Colours::transparentBlack, juce::Colour(255, 255, 255),juce::Font(24, 1));

    AuxPort::setLProperties(_footer, "All Rights Reserved [Build Version 0.1]\nSatyarth Arora ASU2017010100174 \nHimanshu Sindwani ASU2017010100067", juce::Colour(133, 142, 146), juce::Colour(2, 29, 39), juce::Font(18, 1), juce::Justification(juce::Justification::horizontallyJustified));

}

DashboardComponent::~DashboardComponent()
{
}

void DashboardComponent::paint (juce::Graphics& g)
{
   
}

void DashboardComponent::resized()
{
    _survey.setBounds(getRight() / 8, 3 * getBottom() / 10, getRight() / 4, 3 * getBottom() / 10);
    _surveyLabel.setBounds(getRight() / 8, 4.25 * getBottom() / 10, getRight() / 4, getBottom() / 20);


    _result.setBounds(getRight() / 2 + getRight() / 8, 3 * getBottom() / 10, getRight() / 4, 3 * getBottom() / 10);
    _resultLabel.setBounds(getRight() / 2 + getRight() / 8, 4.25 * getBottom() / 10, getRight() / 4, getBottom() / 20);

    
    _footer.setBounds(0, 9 * getBottom() / 10, getRight(), getBottom() / 10);
}
