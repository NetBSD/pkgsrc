# $NetBSD: Makefile,v 1.3 2003/07/17 22:54:42 grant Exp $
#

DISTNAME=	XML-Writer-String-0.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xws
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for writing XML documents based on XML::Writer

DEPENDS+=	p5-XML-Writer-[0-9]*:../../textproc/p5-XML-Writer

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Writer/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
