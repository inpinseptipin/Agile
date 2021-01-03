/*
  ==============================================================================

    MCQQuestion.h
    Created: 27 Dec 2020 9:15:04pm
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
    class MCQQuestion : public juce::Component
    {
    public:
        MCQQuestion()
        {
            addAndMakeVisible(_question);
            addAndMakeVisible(_answer);

            AuxPort::setLProperties(_question, "Add a Question Here");
            _answer.setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colour(255,255,255));
            _answer.setColour(juce::ComboBox::ColourIds::textColourId, juce::Colours::black);
            _answer.setColour(juce::ComboBox::ColourIds::outlineColourId, juce::Colour(0,0,0));
            
        }

        ~MCQQuestion() override
        {
        }

        void paint(juce::Graphics& g) override
        {
           
        }

        void resized() override
        {
            _localBounds = getLocalBounds();
            _question.setBounds(0, 0, _localBounds.getRight() / 2, _localBounds.getBottom() / 2);
            _answer.setBounds(_localBounds.getRight() / 2, 0, _localBounds.getRight() / 2, _localBounds.getBottom());

        }

        void setQuestionID(const juce::String& questionId)
        {
            _questionId = questionId;
        }

        juce::String getQuestionID()
        {
            return _questionId;
        }

        void setQuestion(const juce::String& question)
        {
            _question.setText(question, juce::dontSendNotification);
        }
        void setOptions(const juce::StringArray& options)
        {
            _answer.addItemList(options, 1);
        }
    
        juce::Rectangle<int> _localBounds;
        juce::Label _question;
        juce::ComboBox _answer;
        juce::String _questionId;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MCQQuestion)
    };


    struct MCQQuestionModel
    {
    public:
        MCQQuestionModel(const juce::String& questionId,const juce::String& question,const juce::StringArray& options)
        {
            _questionId = question;
            _question = question;
            _options = options;
        }
        juce::String _questionId = { "MCQ_00" };
        juce::String _question = {"Sample MCQ Question"};
        juce::StringArray _options = { {'1','2'} };
    };
}
