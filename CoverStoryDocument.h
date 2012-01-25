//
//  CoverStoryDocument.h
//  CoverStory
//
//  Created by dmaclach on 12/20/06.
//  Copyright 2006-2007 Google Inc.
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not
//  use this file except in compliance with the License.  You may obtain a copy
//  of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
//  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
//  License for the specific language governing permissions and limitations under
//  the License.
//


#import <Cocoa/Cocoa.h>
#import "GTMDefines.h"
#import "CoverStoryCoverageData.h"

@class CoverStoryArrayController;
@class CoverStoryCodeViewTableView;

@interface CoverStoryDocument : NSDocument<CoverStoryCoverageProcessingProtocol,
                                           NSAnimationDelegate> {
 @private
  IBOutlet CoverStoryCodeViewTableView *codeTableView_;  // the code table
  IBOutlet NSTableView *sourceFilesTableView_;
  IBOutlet CoverStoryArrayController *sourceFilesController_;
  IBOutlet NSProgressIndicator *spinner_;
  IBOutlet NSDrawer *drawer_;
  IBOutlet NSTextView *messageView_;
  IBOutlet NSSearchField *searchField_;
  CGFloat animationWidth_;
  BOOL documentClosed_;
  BOOL hideSDKSources_;
  BOOL hideUnittestSources_;
  BOOL removeCommonSourcePrefix_;

  NSString *filterString_;
  volatile BOOL openingInThread_;  // Are we opening our files in a thread
  CoverStoryCoverageSet *dataSet_;
  NSTextAttachment *errorIcon_;
  NSTextAttachment *warningIcon_;
  NSTextAttachment *infoIcon_;
  unsigned int numFileDatas_;
  NSViewAnimation *currentAnimation_;
  NSString *commonPathPrefix_;
  NSOperation *doneOperation_;

#if DEBUG
  NSDate *startDate_;
#endif
}
+ (void)registerDefaults;

// Opens up the source code file in Xcode.
- (IBAction)openSelectedSource:(id)sender;
- (NSString *)filterString;
- (void)setFilterString:(NSString *)string;
- (IBAction)setUseWildcardPattern:(id)sender;
- (IBAction)setUseRegularExpression:(id)sender;
- (IBAction)toggleMessageDrawer:(id)sender;
- (IBAction)toggleSDKSourcesShown:(id)sender;
- (IBAction)toggleUnittestSourcesShown:(id)sender;
- (IBAction)toggleRemoveCommonSourcePrefix:(id)sender;
- (void)setCommonPathPrefix:(NSString *)newPrefix;
- (NSString *)commonPathPrefix;
- (BOOL)hideSDKSources;
- (BOOL)hideUnittestSources;
- (BOOL)removeCommonSourcePrefix;
- (BOOL)completelyOpened;
- (id)handleExportHTMLScriptCommand:(NSScriptCommand *)command;
- (CoverStoryCoverageSet *)dataSet;
@end
