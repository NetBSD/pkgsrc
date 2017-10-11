# $NetBSD: Makefile,v 1.16 2017/10/11 07:12:24 wiz Exp $

DISTNAME=	HTTP-Server-Simple-Static-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple-Static/
COMMENT=	Serve static files with HTTP::Server::Simple
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-LibMagic-[0-9]*:../../devel/p5-File-LibMagic
DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Server-Simple>=0.01:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Server/Simple/Static/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
