/*
  ==============================================================================

    TextQuestion.h
    Created: 27 Dec 2020 9:05:35pm
    Author:  arsen

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../Automation/Automation.h"

//==============================================================================
/*
*/
namespace AuxPort
{
    class TextQuestion : public juce::Component
    {
    public:
        TextQuestion()
        {
            
            addAndMakeVisible(_question);
            addAndMakeVisible(_answer);

            AuxPort::setLProperties(_question, "Add a Question Here");
            _answer.setColour(juce::TextEditor::ColourIds::backgroundColourId, juce::Colour(255,255,255));
            _answer.setColour(juce::TextEditor::ColourIds::textColourId, juce::Colour(0,0,0));
            _answer.setColour(juce::TextEditor::ColourIds::outlineColourId, juce::Colour(0,0,0));
        }

     
     

        ~TextQuestion() override
        {
        }

        void paint(juce::Graphics& g) override
        {
            
        }

        void resized() override
        {
            _localBounds = getLocalBounds();
            _question.setBounds(0, 0, _localBounds.getRight() / 2, _localBounds.getBottom());
            _answer.setBounds(_localBounds.getRight() / 2, 0, _localBounds.getRight() / 2, _localBounds.getBottom());

        }

        void setQuestion(const juce::String& question)
        {
            _question.setText(question, juce::dontSendNotification);
        }

        void setQuestionID(const juce::String& questionId)
        {
            _questionId = questionId;
        }

        juce::String getQuestionID()
        {
            return _questionId;
        }


        juce::String _questionId = { "0" };
        juce::Label _question = { "0" };
        juce::TextEditor _answer;
        juce::Rectangle<int> _localBounds;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TextQuestion)
    };

    struct TextQuestionModel
    {
    public:
        juce::String _questionId = {"TQ_00"};
        juce::String _question = {"Sample Text Question"};
    };
}
