import TextoCentral from "./TextoCentral";
import PassoStack from "./PassoStack";
import React from "react";

export default (props) => {
  return (
    <PassoStack {...props} avancar="TelaB">
      <TextoCentral corFundo="green">Tela A</TextoCentral>
    </PassoStack>
  );
};
