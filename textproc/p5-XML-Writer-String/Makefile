# $NetBSD: Makefile,v 1.6 2005/04/11 21:47:40 tv Exp $
#

DISTNAME=	XML-Writer-String-0.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xws
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for writing XML documents based on XML::Writer

DEPENDS+=	p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Writer/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
