# $NetBSD: Makefile,v 1.2 2002/09/10 16:06:50 wiz Exp $
#

DISTNAME=	XML-LibXML-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
#SVR4_PKGNAME=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl interface to the libxml2 library

DEPENDS+=	p5-XML-SAX>=0.03:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Checker-[0-9]*:../../textproc/p5-XML-Checker

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/LibXML/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
