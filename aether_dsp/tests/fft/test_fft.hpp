#pragma once

#include "aether_dsp/types.hpp"

#include <QTest>

class TestFft : public QObject
{
    Q_OBJECT
  public:
    TestFft();
  private slots:
    void benchmarkAether();
    void benchmarkPffft();

  private:
    std::vector<aether_dsp::types::fcomplex_buffer_t> inputs_;
};
