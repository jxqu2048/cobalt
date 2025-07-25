// Copyright 2025 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef COBALT_TESTING_BROWSER_TESTS_CONTENT_BROWSER_TEST_SHELL_MAIN_DELEGATE_H_
#define COBALT_TESTING_BROWSER_TESTS_CONTENT_BROWSER_TEST_SHELL_MAIN_DELEGATE_H_

#include <memory>

#include "build/chromeos_buildflags.h"
#include "cobalt/shell/app/shell_main_delegate.h"
#include "third_party/abseil-cpp/absl/types/optional.h"

#if BUILDFLAG(IS_CHROMEOS_LACROS)
// TODO(erikchen): Move #include to .cc file and forward declare
// chromeos::LacrosService to resolve crbug.com/1195401.
#include "chromeos/lacros/lacros_service.h"
#endif

namespace content {

// Acts like normal ShellMainDelegate but inserts behaviour for browser tests.
class ContentBrowserTestShellMainDelegate : public ShellMainDelegate {
 public:
  ContentBrowserTestShellMainDelegate();
  ~ContentBrowserTestShellMainDelegate() override;

  // ContentMainDelegate implementation:
#if BUILDFLAG(IS_CHROMEOS_LACROS)
  absl::optional<int> PostEarlyInitialization(InvokedIn invoked_in) override;
#endif
  // ShellMainDelegate overrides.
  content::ContentBrowserClient* CreateContentBrowserClient() override;

 private:
#if BUILDFLAG(IS_CHROMEOS_LACROS)
  std::unique_ptr<chromeos::LacrosService> lacros_service_;
#endif
};

}  // namespace content

#endif  // COBALT_TESTING_BROWSER_TESTS_CONTENT_BROWSER_TEST_SHELL_MAIN_DELEGATE_H_
