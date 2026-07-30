#pragma once

class Timer
{
public:

    Timer();

    // フレーム開始
    void Update();

    // ΔTime取得（秒）
    float GetDeltaTime() const;

    // 経過時間取得（秒）
    float GetTime() const;

private:

    double m_LastTime;
    double m_CurrentTime;
    float  m_DeltaTime;
};