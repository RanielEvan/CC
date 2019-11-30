using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace WorkShopNETCORE.Controllers
{

    [ApiController]
    [Route("raniel/[controller]")] //Abre o controle com o sufixo controle
    public class GrudeController : ControllerBase
    {

        private static List<Aluno> _lista = new List<Aluno>()
        {
            new Aluno
            {
                Nome = "Raniel",
                Sobrenome = "Evan"
            },
            new Aluno
            {
                Nome = "Teste",
                Sobrenome = "Raniel"
            },
            new Aluno
            {
                Nome = "Explendor",
                Sobrenome = "Valoroso"
            },
        };


        [HttpGet("{nome}")] //Passando so o nome, ele retorna um Olá 'NOME'
        public string GetNome(string nome)
        {
            return $"Olá {nome}!";
        }

        [HttpGet("aluno/")] //Na rota ALUNO, ele faz um get, passando parametros (pode ser valores avulsos ou OBJETO[referenciando as propriedades]
        public List<Aluno> GetAlunos(
            //[FromQuery] string nome,
            //[FromQuery] string sobrenome,
            [FromQuery] AlunoQuery query)
        {
            return _lista.Where(aluno => aluno.Nome.Contains(query.ParteDoNome)
            || aluno.Sobrenome.Contains(query.ParteDoSobrenome)).ToList();
        }


        [HttpPost("aluno")] //Insere o aluno passando o objeto Json...
        public ActionResult InserirAluno([FromBody] Aluno aluno)
        {
            _lista.Add(aluno);
            return Created("aluno", aluno);
        }

        
        [HttpPut("aluno/{nome}")]
        public void ModificarAluno(string nome, [FromBody] Aluno aluno)
        {

        }

    }

    public class Aluno
    {
        public string Nome { get; set; }
        public string Sobrenome { get; set; }

        public override string ToString() //Muda o metodo to string desse obj.
        {
            return $"Nome: {Nome} {Sobrenome}";
        }
    }

    public class AlunoQuery
    {
        public string ParteDoNome { get; set; } = string.Empty;
        public string ParteDoSobrenome { get; set; } = string.Empty;
    }

}
