/*
  ==============================================================================

    Rest.h
    Created: 26 Dec 2020 3:18:35pm
    Author:  arsen

  ==============================================================================
*/

#pragma once

#include<juceHeader.h>

namespace AuxPort
{
    class Rest
    {
    public:

        enum Request
        {
            GET = 0,
            POST = 1,
        };

        //Send a Rest request over HTTPS and retrieves the response in the form of a juce::String
        static juce::String sendRequest(const Request& requestType, const juce::URL& url, juce::StringPairArray& parameters);

        //Use this method to diagnose HTTP request headers and see if it is working properly or not.
        static juce::StringPairArray sendRequest_DG(const Request& requestType, const juce::URL& url, juce::StringPairArray& parameters);
    private:
    };

    class JSON
    {
    public:
        //Primitive JSON parser that can handle key-value pairs
        static juce::StringPairArray parse(juce::String& message);
    };
}
