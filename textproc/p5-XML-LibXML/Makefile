# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:31 jschauma Exp $
#

DISTNAME=	XML-LibXML-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
#SVR4_PKGNAME=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl interface to the libxml2 library

DEPENDS+=	p5-XML-SAX>=0.03:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Checker-[0-9]*:../../textproc/p5-XML-Checker

USE_BUILDLINK2=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/LibXML/.packlist

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
