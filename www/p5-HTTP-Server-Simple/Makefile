# $NetBSD: Makefile,v 1.33 2019/08/11 13:24:46 wiz Exp $

DISTNAME=	HTTP-Server-Simple-0.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Server-Simple
COMMENT=	Perl5 module providing a simple standalone HTTP daemon
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/HTTP/Server/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
