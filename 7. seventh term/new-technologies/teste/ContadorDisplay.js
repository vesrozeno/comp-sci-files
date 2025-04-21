import React, { useState } from "react";
import { Text, Button, TextInput } from "react-native";

export default (props) => {
  return (
    <>
      <Text style={{ fontWeight: "bold", fontSize: 48 }}>{props.num}</Text>
    </>
  );
};
