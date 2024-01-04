# $NetBSD: Makefile,v 1.56 2024/01/04 11:23:19 wiz Exp $

DISTNAME=	XML-Parser-2.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Parser
COMMENT=	Perl extension interface to James Clark's XML parser, expat
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/XML/Parser/.packlist
MAKE_PARAMS+=		EXPATLIBPATH=${BUILDLINK_PREFIX.expat}/lib
MAKE_PARAMS+=		EXPATINCPATH=${BUILDLINK_PREFIX.expat}/include

.include "../../lang/perl5/module.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
