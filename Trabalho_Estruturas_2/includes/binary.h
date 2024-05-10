#pragma once

void write_store_to_binary(Store* stores);
Store* read_store_from_binary();
int read_client_counter_from_binary();
void write_client_counter_to_binary(int client_counter);
void write_client_to_binary(Client* clients);
Client* read_client_from_binary();
// temp
void dealocate_list(Store** stores);