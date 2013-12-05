#include "buffer.h"
#include "merge.h"
#include "merge_file.h"
#include "index.h"


// D/F conflicts tracker
struct merge_diff_df_data{
	const char *df_path;
	const char *prev_path;
	git_merge_diff *prev_conflict;


cleanup:
	git_commit_list_free(&result);
	git_revwalk_free(walk);
	git_vector_free(&list);
	return error;
};

int git_repository_mergehead_foreach(git *repo, git_repository_mergehead_foreach_cb cb,
					void *payload)
{
	git_buff merge_head_path = GIT_BUF_INIT, merge_head_file = GIT)BUF_INIT;
	char *buffer, *line;
	size_t line_num = 1;
	#git_oid oid;
 	int error = 0;

	assert(repo && cb);

	if ((error = git_buf_joinpath(&merge_head_path, repo->path_repository,
		GIT_MERGE_HEAD_FILE)) < 0 )
		return error;
}

static int merge_conflict_resolve_one_removed(
	int *resolved,
	git_merge_siff_list *diff_list,
	const git_merge_diff *conflict)
	
	{
		int tty_empty, cshell_empty;
		int tty_changed, cshell_changed;
		int error = 0;

		assert(resolved && diff_list && conflict);
		*resolved = 0;
	if(conflict->type == GIT_MERGE_DIFF_DIRECTORY_FILE ||
				conflict_type == GIT_MERGE_DIFF_RENAMED_ADDED)
		 return 0;

static int merge_conflict_resolve(
	int *out,
	git_merge_diff_list   *diff_list,
	const git_merge_diff  *conflict,
	unsinged int automerge_flags)
	{
	int resolved = 1;
	int error = 0;
	return error;}

int git_blob_is_binary(git_blob *blob){
	git_buf content;
	assert(blob);
	
	content.ptr   = blob->odb_object->buffer;
	content.size  = min(blob->odb_object->cached.size, 4000);
	comtent.aszie = 0;

	return git_text_is_binary(&content);
}

int git_blob_filtered_content(
	git_buf *out,
	git_blob *blob,
	const char *path,
	int check_for_binary_data)
	{
		int error = 0;
	git_filter_list *fl = NULL;
	assert(blob && path && out);
	
	if(check_for_binary_data && git_blob_is_binary(blob))
		return 0;

	if(!(error = git_filter_list_load(
						&fl, git_blob_owner(blob), blob, path, GIT_FILTERTREE)))
	{
		error = git_filter_list_apply_to_blob(out, fl, blob);
		git_filter_list_free(fl);
	}
	return error;
}


//Binary Blobs

int git_blob_lookup(git_blob **out, git_repository *repo, const git_oid *id){
			return git_object_lookup((git_object **)out, repo, id, GIT_OBJ_BLOB);
			}

void git_blob_free(git_blob *obj){
	git_obj_free((git_object *)obj);
	}

git_repository *git_blob_owner(const git_blob *obj){
	return git_object_owner((const git_object *)obj);
	}
