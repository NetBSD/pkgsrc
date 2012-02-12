# $NetBSD: Makefile,v 1.11 2012/02/12 15:06:16 mspo Exp $

DISTNAME=	Mojolicious-2.48
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mojolicious/SRI/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TE/TEMPIRE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mojolicious.org/
COMMENT=	Perl web framework: The Web In A Box!
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Mojolicious/.packlist

REPLACE_PERL+=	script/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
