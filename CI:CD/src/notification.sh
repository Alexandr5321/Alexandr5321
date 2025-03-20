URL="https://api.telegram.org/bot7813143290:AAHssE53F5y1RhaEgg7cIdiwR4OJEtkgq64/sendMessage"
TEXT="$CI_JOB_NAME status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s -d "chat_id=381063203&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null