[@bs.config {jsx: 2}];

open Jest;
open ExpectJs;

Enzyme.configureEnzyme(Enzyme.react_16_adapter());

let renderReason = () => (<div>
  <ReactDiffViewer.Jsx2
    oldValue="foobar"
    newValue="foobaz"
  />
</div>) |> Enzyme.shallow |> Enzyme.Shallow.childAt(0);

let renderJs = [%bs.raw "() => require('react').createElement(require('react-diff-viewer').default, {
  oldValue: 'foobar',
  newValue: 'foobaz'
})"];

describe("jsx2", () => {
  test("output equal to direct JS rendering", () => {
    let reasonComponent = renderReason();
    let jsComponent = [%bs.raw "renderJs()"];

    expect(Enzyme.Shallow.equals(jsComponent, reasonComponent)) |> toBe(true)
  });
});
