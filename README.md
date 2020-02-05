# bs-react-diff-viewer

[![Build Status](https://travis-ci.com/erykpiast/bs-react-diff-viewer.svg?branch=master)](https://travis-ci.com/erykpiast/bs-react-diff-viewer)
[![dependencies Status](https://david-dm.org/erykpiast/bs-react-diff-viewer/status.svg)](https://david-dm.org/erykpiast/bs-react-diff-viewer)
[![devDependencies Status](https://david-dm.org/erykpiast/bs-react-diff-viewer/dev-status.svg)](https://david-dm.org/erykpiast/bs-react-diff-viewer?type=dev)
[![peerDependencies Status](https://david-dm.org/erykpiast/bs-react-diff-viewer/peer-status.svg)](https://david-dm.org/erykpiast/bs-react-diff-viewer?type=peer)
[![Greenkeeper badge](https://badges.greenkeeper.io/erykpiast/bs-react-diff-viewer.svg)](https://greenkeeper.io/)

ReasonML bindings for [react-diff-viewer](https://github.com/praneshr/react-diff-viewer) library.

## Installation

```
npm i --save bs-react-diff-viewer react-diff-viewer
```

Then add `bs-react-diff-viewer` as a dependency to `bsconfig.json`.

## Usage

```reasonml
[@react.component]
let make = (~before, ~after) => {
  let renderContent = content =>
    <SyntaxHighlighter language=`JavaScript>
      content
    </SyntaxHighlighter>;
  <ReactDiffViewer
    oldValue=before
    newValue=after
    compareMethod=`words
    splitView=false
    renderContent
    styles={ReactDiffViewer.Styles.make(
      ~wordDiff=Styles.wordDiff,
      ~content=Styles.content,
      ~contentText=Styles.contentText,
      ~lineNumber=Styles.lineNumber,
      ~gutter=Styles.gutter,
      ~diffContainer=Styles.diffContainer,
      (),
    )}
  />;;
};
```

### JSX 2

The package provides fallback for projects using older version of JSX syntax.

```reasonml
let component = ReasonReact.statelessComponent("Demo");

let make = (~before, ~after, _children) => {
  ...component,
  render: (_self) => {
    let renderContent = content =>
      <SyntaxHighlighter language=`JavaScript>
        {...content}
      </SyntaxHighlighter>;
    <ReactDiffViewer.Jsx2
      oldValue=before
      newValue=after
      compareMethod=`words
      splitView=false
      renderContent
      styles={ReactDiffViewer.Styles.make(
        ~wordDiff=Styles.wordDiff,
        ~content=Styles.content,
        ~contentText=Styles.contentText,
        ~lineNumber=Styles.lineNumber,
        ~gutter=Styles.gutter,
        ~diffContainer=Styles.diffContainer,
        (),
      )}
    />;
  }
};
```
