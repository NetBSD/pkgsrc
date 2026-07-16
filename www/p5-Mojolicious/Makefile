# $NetBSD: Makefile,v 1.161 2026/07/16 19:06:11 wiz Exp $
#
# When updating this package, please upload the distfile
# since they disappear immediately when new releases happen,
# which is quite often.

DISTNAME=	Mojolicious-9.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SR/SRI/}

MAINTAINER=	rares.aioanei@gmail.com
HOMEPAGE=	http://mojolicio.us/
COMMENT=	Perl web framework: The Web In A Box!
LICENSE=	artistic-2.0

EXTRACT_USING=	gtar	# avoid extended attributes in distfile

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Mojolicious/.packlist

REPLACE_PERL+=	script/*

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
