#pragma once

#include "aether_dsp/types.hpp"

#include <QTest>

class TestFft : public QObject
{
    Q_OBJECT
  private slots:
    void testSize2Fft();
    void testAgainstPffft();
};
