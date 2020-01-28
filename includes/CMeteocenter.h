#pragma once

class CMeteocenter{
	CMeteocenter() {}
public:
	CMeteocenter(const CMeteocenter&) = delete;
	CMeteocenter(CMeteocenter&&) = delete;
	CMeteocenter& operator=(const CMeteocenter&) = delete;
	CMeteocenter& operator=(CMeteocenter&&) = delete;
	static CMeteocenter& GetInstance();
	int GetTemperature() const;
	int GetWindSpeed() const;

};