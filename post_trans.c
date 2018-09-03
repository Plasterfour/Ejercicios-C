#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
	printf("%s:\n", t.name);
	for (int i = 0; i < t.offices_count; i++) {
		printf("\t%d:\n", i);
		for (int j = 0; j < t.offices[i].packages_count; j++) {
			char* id = t.offices[i].packages[j].id;
			printf("\t\t%s\n", id);
		}
	}
}

void append_packages(post_office* office, package* packs_to_append, int ntoappend) {
	int npacks = office->packages_count;
	office->packages = realloc(office->packages, (npacks + ntoappend)*sizeof(package));
	for (int i = npacks; i < npacks+ntoappend; i++) {
		office->packages[i] = packs_to_append[i-npacks];
	}
	office->packages_count = npacks+ntoappend;
}

int is_acceptable(const post_office* office, const package* pack) {
	if (pack->weight >= office->min_weight && pack->weight <= office->max_weight ) {
		return 1;
	}
	else {
		return 0;
	} 
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
	package* packs_to_send = NULL;
	package* packs_to_return = NULL;
	int ntosend = 0;
	int ntoreturn = 0;
	
	post_office* source_office = source->offices+source_office_index;
	post_office* target_office = target->offices+target_office_index;
	
	for (int i = 0; i < source_office->packages_count; i++) {
		package curr_pack = source_office->packages[i];
		
		if (is_acceptable(target_office, &curr_pack)==1) {
			ntosend++;
			packs_to_send = realloc(packs_to_send, ntosend * sizeof(package));
			packs_to_send[ntosend-1] = curr_pack;
		}
		else {
			ntoreturn++;
			packs_to_return = realloc(packs_to_return, ntoreturn * sizeof(package));
			packs_to_return[ntoreturn-1] = curr_pack;
		}
	}
	
	free(source_office->packages);
	source_office->packages = packs_to_return;
	source_office->packages_count = ntoreturn;
	
	append_packages(target_office, packs_to_send, ntosend);
	free(packs_to_send);
}

int total_packages(town* t) {
	int result = 0;
	for (int i = 0; i < t->offices_count; i++) {
		result += t->offices[i].packages_count;
	}
	return result;
}

town town_with_most_packages(town* towns, int towns_count) {
	town* result = towns;
	int  result_npack = total_packages(result);
	for (int i = 1; i < towns_count; i++) {
		int npack = total_packages(towns+i);
		if (npack > result_npack) {
			result = towns+i;
			result_npack = npack;
		}
	}
	return *result;
}

town* find_town(town* towns, int towns_count, char* name) {
	for (int i = 0; i < towns_count; i++) {
		if (strcmp(towns[i].name, name) == 0) {
			return towns+i;
		}
	}
	return NULL;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
