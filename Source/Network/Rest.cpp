/*
  ==============================================================================

    Rest.cpp
    Created: 26 Dec 2020 3:18:35pm
    Author:  arsen

  ==============================================================================
*/

#include "Rest.h"

namespace AuxPort
{
    juce::String Rest::sendRequest(const Request& requestType, const juce::URL& url, juce::StringPairArray& parameters)
    {

        juce::URL m_url = url.withParameters(parameters);
        auto stream = std::unique_ptr<juce::InputStream>(m_url.createInputStream(requestType, nullptr, nullptr, {}, 10000, nullptr, nullptr));
        juce::String message = stream->readEntireStreamAsString();
        return message;
    }

    juce::StringPairArray Rest::sendRequest_DG(const Request& requestType, const juce::URL& url, juce::StringPairArray& parameters)
    {
        juce::StringPairArray* m_headers = nullptr;
        juce::URL m_url = url.withParameters(parameters);
        auto stream = std::unique_ptr<juce::InputStream>(m_url.createInputStream(requestType, nullptr, nullptr, {}, 10000, m_headers, nullptr));
        return m_headers;
    }

    juce::StringPairArray JSON::parse(juce::String& message)
    {
        juce::StringPairArray m_json;
        juce::String m_key;
        juce::String m_value;
        bool keyvalue = false;
        int flag = 0;
        int j = 0;
        int k = 0;
        for (int i = 0; i < message.length();)
        {
            if (message[i] == '{' || message[i] == '}' || message[i] == ',' || message[i] == ':')
                i++;
            if (message[i] == '"')
            {
                if (flag == 0)
                {
                    j = ++i;
                    flag = 1;
                }
                else if (flag == 1)
                {
                    k = i;
                    if (keyvalue == false)
                    {
                        m_key = message.substring(j, k);
                        keyvalue = true;
                        flag = 0;
                    }
                    else if (keyvalue == true)
                    {
                        m_value = message.substring(j, k);
                        m_json.set(m_key, m_value);
                        keyvalue = false;
                        flag = 0;
                    }
                }
            }
            i++;
        }
        return m_json;
    }

}

