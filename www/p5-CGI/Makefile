# $NetBSD: Makefile,v 1.16 2001/11/26 06:50:31 jlam Exp $
#

DISTNAME=       	CGI.pm-2.752
PKGNAME=        	p5-CGI-2.75.2
SVR4_PKGNAME=		p5cgi
CATEGORIES=		www perl5
MASTER_SITES=		http://stein.cshl.org/WWW/software/CGI/ \
			${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://stein.cshl.org/WWW/software/CGI/
COMMENT=		perl5 module for writing forms-based CGI programs

# Some perl packages install their own versions of this module.
# Can't simply define USE_PERL5.
BUILDLINK_DEPENDS.perl=	{perl-5.0*,perl-5.6.0nb2,perl-base>=5.6.0,perl>=5.6.1nb2}

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/.packlist
HTMLDIR=		${PREFIX}/share/doc/html/p5-CGI

do-configure:
	cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	cd ${WRKSRC}/examples;						\
	for file in *.cgi *.pl; do					\
		${SED}	-e "s|^#!/.*|#!${PERL5}|g"			\
			$${file} > $${file}.tmp;			\
		${MV} -f $${file}.tmp $${file};				\
	done;								\
	${CHMOD} +x *.cgi;						\
	${PERL5} make_links.pl

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}/examples
	cd ${WRKSRC}; ${INSTALL_DATA} *.html ${HTMLDIR}
	cd ${WRKSRC}/examples;						\
	${INSTALL_DATA} *.gif *.html *.txt *.xbm ${HTMLDIR}/examples;	\
	${INSTALL_SCRIPT} *.cgi ${HTMLDIR}/examples

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
