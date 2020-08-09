/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include <string>

#include "cyber/common/macros.h"
#include "cyber/time/time.h"

namespace apollo {
namespace common {
namespace time {

class Timer {
 public:
  Timer() = default;

  // no-thread safe.
  void Start();

  // return the elapsed time,
  // also output msg and time in glog.
  // automatically start a new timer.
  // no-thread safe.
  int64_t End(const std::string &msg);

 private:
  apollo::cyber::Time start_time_;
  apollo::cyber::Time end_time_;

  DISALLOW_COPY_AND_ASSIGN(Timer);
};

class TimerWrapper {
 public:
  explicit TimerWrapper(const std::string &msg) : msg_(msg) { timer_.Start(); }

  ~TimerWrapper() { timer_.End(msg_); }

 private:
  Timer timer_;
  std::string msg_;

  DISALLOW_COPY_AND_ASSIGN(TimerWrapper);
};

}  // namespace time
}  // namespace common
}  // namespace apollo
