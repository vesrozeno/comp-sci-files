import React, { useContext } from "react";
import { Alert, FlatList, Text, View } from "react-native";
import { ListItem, Avatar, Icon, Button } from "@rneui/themed";
import UsersContext from "./UserContextFile";

//import Icon from 'react-native-ionicons'
import users from "./users";

export default (props) => {
  const { state, dispatch } = useContext(UsersContext);

  function getUsersItems({ item: user }) {
    return (
      <ListItem
        onPress={() => props.navigation.navigate("UserForm", user)}
        bottomDivider
      >
        <Avatar rounded source={{ uri: user.avatarUrl }} />
        <ListItem.Content>
          <ListItem.Title>{user.name}</ListItem.Title>
          <ListItem.Subtitle>{user.email}</ListItem.Subtitle>
        </ListItem.Content>
        {getActions(user)}
      </ListItem>
    );
  }

  function getActions(user) {
    return (
      <>
        <Button
          onPress={() => props.navigation.navigate("UserForm", user)}
          type="clear"
          icon={<Icon name="edit" size={25} color="orange"></Icon>}
        />
        <Button
          onPress={() => confirmUserDeletion(user)}
          type="clear"
          icon={<Icon name="delete" size={25} color="red"></Icon>}
        />
      </>
    );
  }

  function confirmUserDeletion(user) {
    Alert.alert("Excluir usuário", "Deseja excluir o usuário?", [
      {
        text: "Sim",
        onPress() {
          [
            dispatch({
              type: "deleteUser",
              payload: user,
            }),
          ];
        },
      },
      {
        text: "Não",
      },
    ]);
  }

  return (
    <View>
      <FlatList
        keyExtractor={(user) => user.id.toString()}
        data={state.users}
        renderItem={getUsersItems}
      />
    </View>
  );
};
