# $NetBSD: Makefile,v 1.18 2011/08/14 16:05:58 obache Exp $
#

DISTNAME=	HTTP-Server-Simple-0.43
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5hss
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Server-Simple/
COMMENT=	Perl5 module providing a simple standalone HTTP daemon
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=		auto/HTTP/Server/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
