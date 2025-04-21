import React, { useState } from "react";
import { Text, Button, TextInput } from "react-native";

export default (props) => {
  return (
    <>
      <Button title="+" onPress={props.inc}></Button>
      <Button title="-" onPress={props.dec}></Button>
    </>
  );
};
