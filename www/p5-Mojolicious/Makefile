# $NetBSD: Makefile,v 1.24 2013/05/31 12:42:48 wiz Exp $

DISTNAME=	Mojolicious-3.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
