#include "samplingthread.h"
#include "signaldata.h"
#include <qwt_math.h>
#include <math.h>
#include <iostream>
using namespace std;

SamplingThread::SamplingThread( QObject *parent ):
	QwtSamplingThread( parent ),
	d_frequency( 5.0 ),
	d_amplitude( 20.0 )
{
}

void SamplingThread::setFrequency( double frequency )
{
	d_frequency = frequency;
}

double SamplingThread::frequency() const
{
	return d_frequency;
}

void SamplingThread::setAmplitude( double amplitude )
{
	d_amplitude = amplitude;
}

double SamplingThread::amplitude() const
{
	return d_amplitude;
}

void SamplingThread::sample( double elapsed )
{
	if ( d_frequency > 0.0 ) {
		const QPointF s( elapsed, value( elapsed ) );
		SignalData::instance().append( s );
	}
}

double SamplingThread::value( double timeStamp ) const
{
	double sample;
	cin >> sample;
	return sample;
}
