/*
  ==============================================================================

    SignUpComponent.cpp
    Created: 26 Dec 2020 5:25:47pm
    Author:  arsen

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SignUpComponent.h"

//==============================================================================
SignUpComponent::SignUpComponent()
{
    setSize(800, 800);
    addAndMakeVisible(_name);
    addAndMakeVisible(_phoneNumber);
    addAndMakeVisible(_email);
    addAndMakeVisible(_framework);
    addAndMakeVisible(_footer);
    addAndMakeVisible(_back);
    addAndMakeVisible(_register);


    AuxPort::setLProperties(_phoneNumber, "Enter Phone Number", juce::Colour(255, 255, 255), juce::Colour(0, 0, 0), juce::Font(24, 1), juce::Justification(juce::Justification::horizontallyCentred));
    _phoneNumber.setEditable(true);
    _phoneNumber.setColour(juce::Label::ColourIds::outlineColourId, juce::Colour(0, 0, 0));
    _phoneNumber.setColour(juce::Label::ColourIds::textWhenEditingColourId, juce::Colour(0, 0, 0));
    
    AuxPort::setLProperties(_name, "Enter Your Full Name", juce::Colour(255, 255, 255), juce::Colour(0, 0, 0), juce::Font(24, 1), juce::Justification(juce::Justification::horizontallyCentred));
    _name.setEditable(true);
    _name.setColour(juce::Label::ColourIds::outlineColourId, juce::Colour(0, 0, 0));
    _name.setColour(juce::Label::ColourIds::textWhenEditingColourId, juce::Colour(0, 0, 0));

    AuxPort::setLProperties(_email, "Enter Your Email ID", juce::Colour(255, 255, 255), juce::Colour(0, 0, 0), juce::Font(24, 1), juce::Justification(juce::Justification::horizontallyCentred));
    _email .setEditable(true);
    _email.setColour(juce::Label::ColourIds::outlineColourId, juce::Colour(0, 0, 0));
    _email.setColour(juce::Label::ColourIds::textWhenEditingColourId, juce::Colour(0, 0, 0));

    _framework.setTextWhenNothingSelected("Select Framework");
    _framework.setColour(juce::ComboBox::ColourIds::buttonColourId, juce::Colour(0,0,0));
    _framework.setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colour(0,0,0));
    _framework.setColour(juce::ComboBox::ColourIds::textColourId, juce::Colour(255,255,255));
    _framework.setColour(juce::ComboBox::ColourIds::arrowColourId, juce::Colour(0,0,0));

    _framework.addItem("Scrum", 1);

    AuxPort::setLProperties(_footer, "All Rights Reserved [Build Version 0.1]\nSatyarth Arora ASU2017010100174 \nHimanshu Sindwani ASU2017010100067", juce::Colour(133, 142, 146), juce::Colour(2, 29, 39), juce::Font(18, 1), juce::Justification(juce::Justification::horizontallyJustified));

    AuxPort::setTBProperties(_register, "Register", juce::Colour(133, 142, 146), juce::Colour(0, 0, 0));
    AuxPort::setTBProperties(_back, "Go back to Login", juce::Colour(0, 0, 0), juce::Colour(255, 255, 255));

}

SignUpComponent::~SignUpComponent()
{
}

void SignUpComponent::paint (juce::Graphics& g)
{
    
}

void SignUpComponent::resized()
{
    _phoneNumber.setBounds(getRight() / 4, 3 * getBottom() / 10, getRight() / 2, getBottom() / 20);
    _name.setBounds(getRight() / 4, 4 * getBottom() / 10, getRight() / 2, getBottom() / 20);
    _email.setBounds(getRight() / 4, 5 * getBottom() / 10, getRight() / 2, getBottom() / 20);
    _framework.setBounds(getRight() / 4, 6 * getBottom() / 10, getRight() / 2, getBottom() / 20);
    _back.setBounds(getRight() / 4, 7 * getBottom() / 10, getRight() / 4, getBottom() / 20);
    _register.setBounds(getRight() / 2, 7 * getBottom() / 10, getRight() / 4, getBottom() / 20);
    _footer.setBounds(0, 9 * getBottom() / 10, getRight(), getBottom() / 10);
}

juce::StringPairArray SignUpComponent::getAllValues()
{
    juce::StringPairArray _values;
    _values.set("first_name", _name.getText());
    _values.set("email", _email.getText());
    _values.set("framework", _framework.getText());
    _values.set("mobile", _phoneNumber.getText());
    return _values;
}

void SignUpComponent::clear()
{
    _phoneNumber.setText("Enter Phone Number", juce::dontSendNotification);
    _name.setText("Enter Your Full Name", juce::dontSendNotification);
    _framework.setSelectedItemIndex(0, false);
    
}