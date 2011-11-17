# $NetBSD: Makefile,v 1.5 2011/11/17 09:11:04 hiramatsu Exp $

DISTNAME=	HTTP-Parser-XS-0.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Parser-XS/
COMMENT=	Perl 5 module providing a fast, primitive HTTP request parser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/HTTP/Parser/XS/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
