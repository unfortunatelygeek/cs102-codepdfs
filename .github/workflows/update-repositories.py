from github import Github
g = Github('<your-access-token>')
user = g.get_user()
repos =  user.get_repos()
markdown_content = ""
for repo in repos:
    markdown_content += f"- [{repo.name}]({repo.html_url}): {repo.description}\n"
readme_file = open('README.md', 'r')
readme_content = readme_file.read()
readme_file.close()

updated_readme_content = readme_content.replace('<!-- REPOSITORIES -->', markdown_content)

readme_file = open('README.md', 'w')
readme_file.write(updated_readme_content)
readme_file.close()
