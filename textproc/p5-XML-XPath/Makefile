# $NetBSD: Makefile,v 1.47 2023/07/04 11:30:35 wen Exp $

DISTNAME=	XML-XPath-1.48
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-XPath
COMMENT=	XML XPath software
LICENSE=	artistic-2.0

DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Path-Tiny>=0.076:../../filesystems/p5-Path-Tiny

PERL5_PACKLIST=		auto/XML/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
