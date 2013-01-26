# $NetBSD: Makefile,v 1.21 2013/01/26 19:28:58 rhaen Exp $

DISTNAME=	Mojolicious-3.82
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/SRI/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TE/TEMPIRE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mojolicious.org/
COMMENT=	Perl web framework: The Web In A Box!
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Mojolicious/.packlist

REPLACE_PERL+=	script/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
