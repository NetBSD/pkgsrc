# $NetBSD: Makefile,v 1.18 2012/09/15 17:53:08 mspo Exp $

DISTNAME=	Mojolicious-3.41
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
