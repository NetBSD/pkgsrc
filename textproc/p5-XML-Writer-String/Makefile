# $NetBSD: Makefile,v 1.15 2012/10/25 06:56:41 asau Exp $
#

DISTNAME=	XML-Writer-String-0.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5xws
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for writing XML documents based on XML::Writer

DEPENDS+=	p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer

PERL5_PACKLIST=		auto/XML/Writer/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
