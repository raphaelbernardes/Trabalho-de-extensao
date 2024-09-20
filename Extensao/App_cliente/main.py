#####################################################################
# AUTOR: RAPHAEL ADILSON BERNARDES ##################################
# EMAIL: raphaelbernardes.dev@gmail.com #############################
# GIT: https://github.com/raphaelbernardes/Trabalho-de-extensao.git #
#####################################################################

import flet as ft
import socket


def transmitir(host='localhost', port=567, msg="texto ja formatado"):
    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # Connect the socket to the server
    server_address = (host, port)
    print("Connecting to %s port %s" % server_address)
    sock.connect(server_address)
    # Send data
    try:
        # Send data
        message = msg
        print("Enviado %s" % message)
        sock.sendall(message.encode('utf-8'))
        # Look for the response
        print("Recebido:", sock.recv(20))
    except socket.error as e:
        print("Socket error: %s" % str(e))
    except Exception as e:
        print("Other exception: %s" % str(e))
    finally:
        print("Closing connection to the server")
        sock.close()


def main(page: ft.Page):
    page.title = "Rascunho de Laudos"
    page.adaptive = True
    page.scroll = ft.ScrollMode.ALWAYS

    def limpar_tela(e):
        txt_cpf.value = None
        txt_bo.value = None
        txt_nome.value = None
        txt_laudo.value = None
        page.update()

    def enviar(e):
        dados = txt_cpf.value + ";"
        dados += txt_bo.value + ";"
        dados += txt_nome.value + ";"
        dados += txt_laudo.value
        server = txt_server.value
        transmitir(server, 567, dados)
        limpar_tela(e)

    lb_periciado = ft.Text(value="DADOS DO PERICIADO:", text_align=ft.TextAlign.CENTER)
    lb_laudo = ft.Text(value="LAUDO:", text_align=ft.TextAlign.CENTER)

    txt_server = ft.TextField(value="", label="SERVIDOR:", text_align=ft.TextAlign.CENTER, bgcolor="silver")

    txt_cpf = ft.TextField(value="",label="CPF:", text_align=ft.TextAlign.CENTER, bgcolor="silver")
    txt_bo = ft.TextField(value="",label="BOLETIM DE OCORRÊNCIA:", text_align=ft.TextAlign.CENTER, bgcolor="silver")
    txt_nome = ft.TextField(value="",label="NOME:", text_align=ft.TextAlign.CENTER, bgcolor="silver")
    txt_laudo = ft.TextField(value="", text_align=ft.TextAlign.LEFT, multiline=True,
                             min_lines=5, max_lines=5, bgcolor="white", color="black")

    btn_salvar = ft.ElevatedButton(text="SALVAR", bgcolor="blue", on_click=enviar)

    btn_limpar = ft.ElevatedButton(text="LIMPAR", bgcolor="red", on_click=limpar_tela)

    page.add(
        ft.SafeArea(
            ft.Column(
                [ txt_server, lb_periciado, txt_cpf, txt_bo, txt_nome, lb_laudo,
                 txt_laudo, ft.Row([btn_limpar, btn_salvar], alignment=ft.MainAxisAlignment.CENTER, )]
            )
        )
    )


ft.app(main)
