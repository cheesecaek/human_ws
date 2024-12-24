from openai import AzureOpenAI
import httpx
from httpx_socks import SyncProxyTransport

class OpenAIClient:
    def __init__(self, base_url_input, api_key_input,):
        self.proxy_transport = SyncProxyTransport.from_url("socks5://127.0.0.1:7897")
        self.client = AzureOpenAI(
        azure_endpoint = base_url_input,
        api_key = api_key_input,
        api_version = "2024-02-01",
        http_client = httpx.Client(transport = self.proxy_transport)
    )
    def get_response(self, system_prompt, user_message):
        """获取 OpenAI 的聊天模型返回结果。"""
        completion = self.client.chat.completions.create(
                    model="gpt-4o",
                    messages=[
                        {'role': 'system', 'content': system_prompt},
                        {'role': 'user', 'content': user_message}],
                )
        return completion.choices[0].message.content