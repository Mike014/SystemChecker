#include <JuceHeader.h>
#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Determine the system type
    juce::String message;

    #if JUCE_WINDOWS
        message = "Hello Desktop (Windows)";
    #elif JUCE_IOS
        message = "Hello iPhone";
    #else
        message = "Unknown System";
    #endif

    // Set up the label to display the message
    systemLabel.setText(message, juce::dontSendNotification);
    systemLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(systemLabel);

    setSize(400, 200);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    /*g.setFont (juce::Font(16.0f));
    g.setColour (juce::Colours::white);*/
    // g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    systemLabel.setBounds(getLocalBounds());
}
