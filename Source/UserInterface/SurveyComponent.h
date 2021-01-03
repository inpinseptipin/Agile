/*
  ==============================================================================

    SurveyComponent.h
    Created: 27 Dec 2020 10:56:19pm
    Author:  arsen

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Assets.h"


//==============================================================================
/*
*/
class SurveyComponent : public juce::Component
{
public:
    SurveyComponent();
    ~SurveyComponent() override;

    enum Question
    {
        TEXT = 1,
        MCQ = 2,
        ALL = 3
    };
    void paint(juce::Graphics&) override;
    void resized() override;
    void reset(const Question& questionType, std::vector<AuxPort::TextQuestionModel>& textQuestions , std::vector<AuxPort::MCQQuestionModel>& mcqQuestions);
    void page(unsigned int pageNumber);
    void unloadPage(unsigned int pageNumber);


private:
    
    AuxPort::TextQuestion* _textQuestions;
    Question _questionType;
    juce::Label _footer;
    juce::TextButton _nextPage;
    juce::TextButton _prevPage;
    unsigned int _noofPages;
    unsigned int _noOfQuestions;
    unsigned int _currentPage;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SurveyComponent)
};


