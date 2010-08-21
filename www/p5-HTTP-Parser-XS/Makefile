# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:53 seb Exp $

DISTNAME=	HTTP-Parser-XS-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Parser-XS/
COMMENT=	Perl 5 module providing a fast, primitive HTTP request parser
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/HTTP/Parser/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
