/*
  ==============================================================================

    SurveyComponent.cpp
    Created: 27 Dec 2020 10:56:19pm
    Author:  arsen

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SurveyComponent.h"

//==============================================================================
SurveyComponent::SurveyComponent()
{
    _textQuestions = nullptr;
    setSize(800, 800);
    _noofPages = 1;
    _noOfQuestions = 2;
    _currentPage = 1;
    _questionType = Question::TEXT;

    
    addAndMakeVisible(_nextPage);
    addAndMakeVisible(_prevPage);
    addAndMakeVisible(_footer);
    
    AuxPort::setTBProperties(_prevPage, "Go to Previous Page");

    _prevPage.onClick = [this]
    {
        if (_currentPage > 1)
        {
            unloadPage(_currentPage);
            _currentPage--;
            page(_currentPage);
        }
        
    };

    _nextPage.onClick = [this]
    {
        if (_currentPage < _noofPages)
        {
            unloadPage(_currentPage);
            _currentPage++;
            page(_currentPage);
        }
    };
    AuxPort::setTBProperties(_nextPage, "Go to Next Page");
    AuxPort::setLProperties(_footer, "All Rights Reserved [Build Version 0.1]\nSatyarth Arora ASU2017010100174 \nHimanshu Sindwani ASU2017010100067", juce::Colour(133, 142, 146), juce::Colour(2, 29, 39), juce::Font(18, 1), juce::Justification(juce::Justification::horizontallyJustified));
    
}

SurveyComponent::~SurveyComponent()
{
    if (_textQuestions != nullptr)
    {
        delete[] _textQuestions;
        _textQuestions = nullptr;
    }
}

void SurveyComponent::paint (juce::Graphics& g)
{
    
}

void SurveyComponent::resized()
{

    if (Question::TEXT)
    {
        if (_textQuestions != nullptr)
        {
            page(_currentPage);
        }
        
    }
    _prevPage.setBounds(getRight() / 4, 7 * getBottom() / 10, getRight() / 8, getBottom() / 20);
    _nextPage.setBounds(getRight()-getRight()/4, 7 * getBottom() / 10, getRight() / 8, getBottom() / 20);
    _footer.setBounds(0, 9 * getBottom() / 10, getRight(), getBottom() / 10);
}

void SurveyComponent::page(unsigned int pageNumber)
{
    if (pageNumber <= _noofPages)
    {
        if (_questionType == Question::TEXT)
        {
            int i = (pageNumber - 1) * 4;
            for (i; i < pageNumber*4; i++)
            {
                _textQuestions[i].setBounds(getRight() / 8, (2 + (i%4)) * getBottom() / 10, 6*getRight()/8, getBottom() / 20);
                _textQuestions[i].setVisible(true);
            }
        }
        
    }
}

void SurveyComponent::unloadPage(unsigned int pageNumber)
{
    if (pageNumber <= _noofPages)
    {
        if (_questionType == Question::TEXT)
        {
            int i = (pageNumber - 1) * 4;
            for (i; i < pageNumber * 4; i++)
            {
                //_textQuestions[i].setBounds(getRight() / 8, (2 + (i % 4)) * getBottom() / 10, 6 * getRight() / 8, getBottom() / 20);
                _textQuestions[i].setVisible(false);
            }
        }

    }
}

void SurveyComponent::reset(const Question& questionType, std::vector<AuxPort::TextQuestionModel>& textQuestions , std::vector<AuxPort::MCQQuestionModel>& mcqQuestions)
{
    _questionType = questionType;
    if (_questionType == Question::TEXT)
    {
        if (_textQuestions != nullptr)
        {
            delete[] _textQuestions;
            _textQuestions = nullptr;
        }
        _textQuestions = new AuxPort::TextQuestion[textQuestions.size()];

        _noOfQuestions = textQuestions.size();
        for (int i = 0; i < textQuestions.size(); i++)
        {
            _textQuestions[i].setQuestion(textQuestions[i]._question);
            _textQuestions[i].setQuestionID(textQuestions[i]._questionId);
            addChildComponent(_textQuestions[i]);
        }
        int totalQuestions = _noOfQuestions;
        while (totalQuestions > 0)
        {
            _noofPages++;
            totalQuestions = -4;
        }
        resized();
    }
}



