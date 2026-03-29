# $NetBSD: Makefile,v 1.63 2026/03/29 09:16:57 wiz Exp $

DISTNAME=	XML-Parser-2.54
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TODDR/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Parser
COMMENT=	Perl extension interface to James Clark's XML parser, expat
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
TOOL_DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
TOOL_DEPENDS+=	p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install

PERL5_PACKLIST=		auto/XML/Parser/.packlist
MAKE_PARAMS+=		EXPATLIBPATH=${BUILDLINK_PREFIX.expat}/lib
MAKE_PARAMS+=		EXPATINCPATH=${BUILDLINK_PREFIX.expat}/include

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/perl5/module.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
