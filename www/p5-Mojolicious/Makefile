# $NetBSD: Makefile,v 1.80 2015/09/26 05:05:34 wen Exp $

DISTNAME=	Mojolicious-6.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mojolicio.us/
COMMENT=	Perl web framework: The Web In A Box!
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Mojolicious/.packlist

REPLACE_PERL+=	script/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
